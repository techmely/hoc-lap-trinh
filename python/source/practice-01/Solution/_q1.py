
def get_input():
    while True:
        raw = input("Enter a positive integer number: ")
        try:
            try:
                num = int(raw)
            except:
                raise Exception("The number must be a positive number.")

            if num < 0:
                raise Exception("The number must be positive.")

            return num

        except Exception as e:
            print(e)
            continue


def gcd(a, b):
    if b == 0:
        return a
    if b > a:
        (a, b) = (b, a)
    return gcd(b, a-b)


a = get_input()
b = get_input()

print("GCD of", a, ",", b, "is", gcd(a, b))
