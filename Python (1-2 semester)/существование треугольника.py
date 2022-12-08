from math import sqrt

x1,y1 = map(int, input('1 = ').split())
x2,y2 = map(int, input('2 = ').split())
x3,y3 = map(int, input('3 = ').split())

ab = sqrt((x2-x1)**2 + (y2-y1)**2)
bc = sqrt((x3-x2)**2 + (y3-y2)**2)
ac = sqrt((x3-x1)**2 + (y3-y1)**2)

if (ab <= (ac + bc)) or (ac <= (ab + bc)) or (bc <= (ac + ab)):
    
    x4,y4 = map(int, input('4 = ').split())

    ao = sqrt((x4-x1)**2 + (y4-y1)**2)
    bo = sqrt((x4-x2)**2 + (y4-y2)**2)
    co = sqrt((x4-x3)**2 + (y4-y3)**2)
    p1 = (ao + bo + ab)/2
    p2 = (ao + co + ac)/2
    p3 = (bo + co + bc)/2            
    H_aob = ((2/ab)*(sqrt(p1*(p1-ao)*(p1-bo)*(p1-ab))))
    H_aoc = ((2/ac)*(sqrt(p2*(p2-ao)*(p2-co)*(p2-ac))))
    H_boc = ((2/bc)*(sqrt(p3*(p3-bo)*(p3-co)*(p3-bc))))
    H_Max = max(H_aob, H_aoc, H_boc)
    print('{:.5g}'.format(H_Max))
else:
    print('треугольник не существует')
