def tax_included(price, rate):
    return int(price + price * rate)

print(tax_included(int(input()), 0.1))