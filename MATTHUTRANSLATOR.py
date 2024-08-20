from unidecode import unidecode

def convert_to_telex(input_string):
    telex_rules = {
        'a': 'a', 'ă': 'aw', 'â': 'aa', 'b': 'b', 'c': 'c', 'd': 'd', 'đ': 'dd',
        'e': 'e', 'ê': 'ee', 'g': 'g', 'h': 'h', 'i': 'i', 'j': 'j', 'k': 'k',
        'l': 'l', 'm': 'm', 'n': 'n', 'o': 'o', 'ô': 'oo', 'ơ': 'ow', 'p': 'p',
        'q': 'q', 'r': 'r', 's': 's', 't': 't', 'u': 'u', 'ư': 'uw', 'v': 'v',
        'x': 'x', 'y': 'y', 'z': 'z'
    }

    result = []
    for char in unidecode(input_string):
        result.append(telex_rules.get(char.lower(), char))

    return ''.join(result)

def main():
    st = input("Nhập chuỗi: ")

    for i in range(1, 26):
        res = ""
        for c in st:
            if c != ' ':
                if c.isupper():
                    if ord(c) + i > 90:
                        res += chr(ord(c) + i - 26)
                    else:
                        res += chr(ord(c) + i)
                else:
                    if ord(c) + i > 122:
                        res += chr(ord(c) + i - 26)
                    else:
                        res += chr(ord(c) + i)
            else:
                res += " "

        telex_result = convert_to_telex(res)
        print(telex_result)

if __name__ == "__main__":
    main()
