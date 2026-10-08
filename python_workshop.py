# ==================================================
# PYTHON 101 WORKSHOP
# ==================================================


# ==================================================
# 1) TEMEL VKI HESAPLAMA
# Konular: input, float, işlem, if/elif/else, print
# ==================================================
kilo = float(input("Kilonuz (kg): "))
boy_cm = float(input("Boyunuz (cm): "))

boy_m = boy_cm / 100
vki = kilo / (boy_m ** 2)

print(f"VKI: {vki:.1f}")

if vki < 18.5:
    print("Durum: Zayıf")
elif vki < 25:
    print("Durum: Normal")
elif vki < 30:
    print("Durum: Fazla kilolu")
else:
    print("Durum: Obez")


# ==================================================
# 2) FOR DÖNGÜSÜ - ORTALI PİRAMİT
# Konular: for, range, string çarpma
# ==================================================
n = 8
for i in range(1, n + 1):
    print(" " * (n - i) + "*" * (2 * i - 1))


# ==================================================
# 3) NESTED LOOP - ÇARPIM TABLOSU
# Konular: iç içe for, f-string, end=
# ==================================================
for i in range(1, 11):
    for j in range(1, 11):
        print(f"{i * j:4}", end="")
    print()


# ==================================================
# 4) RECURSION (ÖZYİNELEME)
# Konular: fonksiyon, kendini çağırma, taban durumu
# ==================================================

# Factorial
def factorial(num):
    if (num == 1):
        return num
    else:
        return num*factorial(num-1)
print(factorial(9))

# Square
def square(power, num):
    if (power == 1):
        return num
    else:
        return num*square(power-1, num)
print(square(7,2))


# ==================================================
# 5) BINARY SEARCH
# Konular: liste, sort, while, if/elif/else, indeks
# Not: Liste sıralı olmak zorunda
# ==================================================
my_list = [1, 5, 8, 7, 6, 4, 0]
my_list.sort()
print(my_list)

def binary_search(l, target):
    left = 0
    right = len(l) - 1
    while left <= right:
        mid = (left + right)//2
        if (target > l[mid]):
            left = mid + 1
        elif (target < l[mid]):
            right = mid - 1
        else:
            return mid
    return -1

x = binary_search(my_list, 4)
print(x)
