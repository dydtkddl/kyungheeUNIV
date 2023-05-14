def number_to_string(agrument):
    match agrument:
        case 0:
            return "zero"
        case 1:
            return "one"
        case 2:
            return "two"
        case default:
            return "nothing"


print(number_to_string(0))
print(number_to_string(1))
print(number_to_string(2))
print(number_to_string(3))
print(number_to_string(4))