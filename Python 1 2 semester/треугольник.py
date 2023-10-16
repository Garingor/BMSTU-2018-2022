# Программа по определению длин сторон треугольника; длины высоты, проведенного из наименьшего
# угла;является ли треугольник остроугольным;по определению принадлежности новой введеной точки
# внутреннего пространства треугольника;если эта точка принадлежит треугольнику, то идет
# поиск близжайшего расстояния от точки до стороны треугольника или её продолжения.

# AB, BC, CA - стороны треугольника, построенного по точкам
# x_1, y_1; x_2, y_2; x_3, y_3; x_4, y_4 - координаты точек
# arccos_A, arccos_B, arccos_C - углы треугольника в градусах
# min_angle - минимальный угол в треугольнике ABC
# p - полупериметр для нахождения высоты треугольника ABC
# H_ABC - высота, проведенная из наименьшего угла
# OA, OB, OC - отрезки от введеной точки до точек треугольника
# p_AOC, p_AOB, p_BOC - полупериметры для нахождения высоты треугольников AOC, AOB, BOC
# H_AOC, H_AOB, H_BOC - высоты треугольников AOC, AOB, BOC
# H_min - минимальное расстояние от точки до близжайшей прямой треугольника ABC

# Cавинов Егор ИУ-14Б

from math import sqrt, acos, pi 

x_1, y_1 = map(float, input('\nВведите координаты x и y первой точки = ').split())
x_2, y_2 = map(float, input('\nВведите координаты x и y второй точки = ').split())
x_3, y_3 = map(float, input('\nВведите координаты x и y третьей точки = ').split())

if (x_1 == x_2 == x_3) or (y_1 == y_2 == y_3):
    print('\nтреугольник не существует, так как точки лежат на одной прямой')
    input('\nPress ENTER to exit')
    
else:
    AB = sqrt((x_2 - x_1) ** 2 + (y_2 - y_1) ** 2)
    BC = sqrt((x_3 - x_2) ** 2 + (y_3 - y_2) ** 2)
    CA = sqrt((x_1 - x_3) ** 2 + (y_1 - y_3) ** 2)

    if (AB + BC <= CA) or (BC + CA <= AB) or (AB + CA <= BC):
        print('\nТреугольника не существует, не выполнются условия существования треугольника')
        input('\nPress ENTER to exit')
        
    else:
        print('\nAB = {:.5g}'.format(AB), '\nBC = {:.5g}'.format(BC), '\nCA = {:.5g}'.format(CA))

        arccos_A = ((acos((AB ** 2 + CA ** 2 - BC ** 2) / (2 * AB * CA))) * 180) / pi
        arccos_B = ((acos((AB ** 2 + BC ** 2 - CA ** 2) / (2 * AB * BC))) * 180) / pi
        arccos_C = ((acos((CA ** 2 + BC ** 2 - AB ** 2) / (2 * CA * BC))) * 180) / pi
        min_angle = min(arccos_A, arccos_B, arccos_C)
        p = (AB + BC + CA) / 2
        H_ABC = (2 / min(AB, BC, CA)) * (sqrt(p * (p - AB) * (p - BC) * (p - CA)))
        S_ABC = (sqrt(p * (p - CA) * (p - BC) * (p - AB)))
        E = 1e-8

        print('\n\nmin_angle = {:.5g}'.format(min_angle), '\nH_ABC = {:.5g}'.format(H_ABC))

        x_4, y_4 = map(float, input('\nВведите координаты x и y четвертой точки = ').split())

        OA = (sqrt((x_1 - x_4) ** 2 + (y_1 - y_4) ** 2))
        OB = (sqrt((x_2 - x_4) ** 2 + (y_2 - y_4) ** 2))
        OC = (sqrt((x_3 - x_4) ** 2 + (y_3 - y_4) ** 2))
        p_AOC = (OA + OC + CA) / 2
        p_AOB = (OA + AB + OB) / 2
        p_BOC = (OB + OC + BC) / 2
        H_AOC = (2 / CA) * (sqrt(p_AOC * (p_AOC - OA) * (p_AOC - OC) * (p_AOC - CA)))
        H_AOB = (2 / AB) * (sqrt(p_AOB * (p_AOB - OA) * (p_AOB - AB) * (p_AOB - OB)))
        H_BOC = (2 / BC) * (sqrt(p_BOC * (p_BOC - OB) * (p_BOC - OC) * (p_BOC - BC)))
        S_3 = (sqrt(p_AOC * (p_AOC - OA) * (p_AOC - OC) * (p_AOC - CA))) + (sqrt(p_AOB * (p_AOB - OA) * (p_AOB - AB) * (p_AOB - OB))) + (sqrt(p_BOC * (p_BOC - OB) * (p_BOC - OC) * (p_BOC - BC)))
        H_min = min(H_AOB, H_BOC, H_AOC)

        if abs(S_ABC - S_3) < E :
            print('\nточка лежит в треугольнике')
            print('\nOA = {:.5g}'.format(OA), '\nOB = {:.5g}'.format(OB), '\nOC = {:.5g}'.format(OC),
                  '\nH_AOC = {:.5g}'.format(H_AOC), '\nH_AOB = {:.5g}'.format(H_AOB),
                  '\nH_BOC = {:.5g}'.format(H_BOC), '\n\nH_min = {:.5g}'.format(H_min))
                
        else:
            print("\nточка не лежит в треугольнике или лежит на стороне треугольника")

        if (arccos_A < 90) and (arccos_B < 90) and (arccos_C < 90):
            print('\nтреугольник - остроугольный')
            input('\nPress ENTER to exit')
            
        else:
            print('\nтреугольник не является остроугольным')
            input('\nPress ENTER to exit')
