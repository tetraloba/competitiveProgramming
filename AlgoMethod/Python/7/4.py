# 2023/06/14 09:41:21
# 2023/06/14 09:46:57 AC.
PI = 3.14
def circleArea(r):
    return r * r * PI
def cylinderVolume(r, h):
    return r * r * PI * h
def printCircleArea(r):
    print(f"半径 {r} cm の円の面積は {circleArea(r)} cm^2")
def printCylinderVolume(r, h):
    print(f"底面の半径が {r} cm、高さが {h} cm の円柱の体積は {cylinderVolume(r, h)} cm^3")
printCircleArea(3)
printCircleArea(5)
printCircleArea(10)
printCylinderVolume(2, 4)
printCylinderVolume(6, 10)
printCylinderVolume(10, 3)
