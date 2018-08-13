
def main():
    num_str = str(2**1000)
    num_length = len(num_str)

    sum = 0;
    for i in range(0, num_length):
        sum += int(num_str[i])

    print(sum)

if __name__ == '__main__':
    main()
