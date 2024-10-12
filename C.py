a = input()
l = []
number = ""
for i in a:
    if i == "-" or i == "+" or i == "*" or i == " " and number != "" and number != '':
        l.append(int(number))
        number = ""
    if i == "-":
        k = l[len(l) - 2] - l[len(l) - 1]
        l.pop(len(l) - 1)
        l.pop(len(l) - 1)
        l.append(k)

    elif i == "+":
        k = l[len(l) - 1] + l[len(l) - 2]
        l.pop(len(l) - 1)
        l.pop(len(l) - 2)
        l.append(k)
    elif i == "*":
        k = l[len(l) - 1] * l[len(l) - 2]
        l.pop(len(l) - 1)
        l.pop(len(l) - 2)
        l.append(k)
    else:
        if i != " ":
            number += i
print(l[0])