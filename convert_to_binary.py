def decimal_to_binary(decimal_number):
    # Chuyển số thập phân sang nhị phân bằng hàm tích hợp sẵn của Python
    return bin(int(decimal_number))[2:]

if __name__ == "__main__":
    decimal_number = int(input())
    binary_number = decimal_to_binary(decimal_number)
    
    print(binary_number)
