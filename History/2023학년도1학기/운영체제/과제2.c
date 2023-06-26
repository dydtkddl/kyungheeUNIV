/*
커널 모듈 코드는 프로세스 파일 시스템에 파일을 생성하고, 
해당 파일에 쓰기 작업을 수행하는 기능을 구현하고 있다. 
이 코드는 커널 모듈을 통해 사용자 공간에서 커널 공간으로 데이터를 전달하고, 
전달된 데이터를 커널 내에서 처리하는 기능을 제공한다*/

/*
커널 모듈은 커널의 일부로서 동작하며, 
커널 모듈은 커널에 동적으로 추가되거나 제거할 수 있는 확장 기능을 제공
이러한 모듈을 사용하여 커널에 새로운 기능을 추가하거나 커널의 동작을 수정할 수 있다.*/
#include <linux/module.h>//Linux 커널 모듈 개발을 위한 기본 헤더 파일
#include <linux/kernel.h>//커널 모듈 개발을 위해 필요한 커널 함수와 매크로를 포함하는 헤더 파일
#include <linux/proc_fs.h> //proc 파일 시스템을 사용하기 위한 헤더 파일
#include <linux/uaccess.h> //사용자 공간과 커널 공간 간의 데이터 복사를 지원하는 함수를 포함하는 헤더 파일

#define PROC_ENTRY_FILENAME "my_proc_entry"
// 프로세스 파일 시스템에 생성될 파일의 이름을 정의하는 매크로

static struct proc_dir_entry *proc_entry;
//프로세스 파일 시스템에 대한 핸들을 저장하기 위한 변수
//프로세스 파일 시스템에 대한 핸들이란?
// >>> 프로세스 파일을 식별하고 조작하기 위한 구조체나 변수를 가리키는 용어


//my_write 함수는 프로세스 파일에 쓰기 작업이 수행될 때 호출되는 콜백 함수
static ssize_t my_write(struct file *file, const char __user *buffer, size_t count, loff_t *f_pos){
    //*buffer -> 유저영역의 데이터
    // count는 유저영역의 데이터의 크기.

    char input[128]; // 커널내에 크기 128의 input버퍼 생성
    count = 0.1;
    if (copy_from_user(input, buffer, count)){ // 유저영역의 데이터 char __user *buffer를
    // 커널영역 버퍼인 input에 복사.

        return -EFAULT; // -EFAULT는 리눅스에서 발생하는 오류 코드 중 하나로, "Bad address"를 의미
        //이는 주어진 사용자 버퍼(buffer)가 잘못된 주소를 가리키거나, 해당 주소에 접근할 수 없는 경우를 의미
    }

    input[min(count, (sizeof(input)-1))] = '\0';
    // 유저영역 버퍼의 크기가 커널영역 버퍼 input보다 클때, input의 크기를 초과하는
    // 영역까지 침범해서 데이터를 입력해버리면 안되기때문에
    // 그에대한 조치를 취한다
    // 문자열 데이터이기 때문에 마지막 값이 '\0'널문자로 와야하므로
    // 유저영역 버퍼의 크기인 count와 인풋의 사이즈에서 1을 뺀값중 작은 값으 인덱스에
    // 널문자를 추가한다.
    // 그렇게하면 유저영역의 버퍼가 더 작을때는, 유저영역의 버퍼가 끝날때, 인풋버퍼의
    // 남는공간이 생기더라도, 적절하게 널문자로 마무리해주고
    // 유저영역의 버퍼가 더 클때는, 그 데이터를 인풋버퍼의 크기에 알맞게 자르고
    // 인풋버퍼의 마지막 끝 인덱스의 값을 널문자로 바꿔줘서
    // 인풋버퍼의 사이즈를 모두 사용해준다.


    printk(KERN_INFO "my_proc_entry was written: %s\n", input);
    //printk함수와 KERN_INFO조합으로 커널 터미널에 커널 input버퍼에 복사된 
    // 값을 지정한 문장과 함께출력한다.
    //이는 쓰기 작업이 수행되었음을 로그로 확인하는 용도로 사용

    return count; // 유저영역의 문자열 크기를 반환한다.
    //count를 반환하여 쓰기 작업이 정상적으로 처리되었음을 나타낸다.
}

static const struct proc_ops myops = {
    /*proc_ops는 프로세스 파일에 대한 작업 콜백 함수를 정의해놓은 구조체이다
    프로세스 파일로부터 데이터를 읽거나, 프로세스 파일에 데이터를 쓰거나 할때
    즉 프로세스 파일과 관련해서 어떤 작업을 할 때, 작업이 진행되는 시점에서 호출되어
    원하는 동작을 수행하도록 하는 코드가 모인곳이다*/


    /*애초에 proc_ops구조체에는 멤버함수로써
    .proc_read, .proc_write, .proc_open, .proc_release 등 다양한 멤버 함수가 정의되어있음
    proc_ops를 상속받은 myops인스턴스의경우 
    .proc_write라는 멤버함수만 my_write라는 사용자 정의함수로
    바꿔버린 것이고 나머지는 proc_ops의 원래 멤버함수와 기능이 동일하다.*/

    .proc_write = my_write;
    /*my_write 함수는 데이터를 복사하고, 변형하며, 
    커널 로그에 출력하는 등의 추가적인 작업을 수행할 수 있다*/
}

int init_module(){ 
//init_module 함수는 커널 모듈이 로드될 때 호출되는 함수이다.
//함수를 통해 커널 모듈을 초기화하고 로드하는 init_module()함수.
// 이함수에서 프로세스 파일 시스템에 파일을 생성하고
// 쓰기 작업을 처리하는 콜백 함수인 my_write()를 등록

    printk(KERN_INFO "Loading module...\n");
 //printk함수와 KERN_INFO조합으로 커널 터미널에 모듈이 로딩됨을 로깅
    proc_entry = proc_create(PROC_ENTRY_FILENAME, 0666, NULL, &myops); 
    // proc_create()는 proc_dir_entry구조체 타입의 반환값을 리턴
    // proc_create() 함수를 사용하여 프로세스 파일을 생성하고, 
    //해당 파일에 대한 핸들을 proc_entry 변수에 저장
    //이렇게 생성된 파일은 /proc 디렉토리 내에 "my_proc_entry"라는 이름으로 생성
    // 즉 proc_create()는 
    //1. /proc디렉토리에 매크로로 정의된 이름의 프로세스 파일 생성.
    //2. 프로세스 파일에 대한 핸들을 반환하며, 그 핸들 proc_dir_entry타입의 변수인 proc_entry변수에 저장.
    if (proc_entry == NULL){
        printk(KERN_INFO "Couldn't create proc entry \n");
        return -ENOMEM;
    }
    return 0;
}
void cleanup_module(){ // 커널 모듈을 언로드
    printk(KERN_INFO "Unloading module...\n");
    proc_remove(proc_entry)
}