dist = int(input())
fare = 650
fare += 300 * dist
if dist >= 100:
    fare -= 5000
print(fare)