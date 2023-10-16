from django.shortcuts import render
from .forms import *
from django.contrib.auth.models import Group
from django.contrib import messages
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from .decorators import *
import qrcode

#@login_required(login_url='login')
def home(request):
    return render(request, 'accounts/home.html')

#@login_required(login_url='login')
def objects(request):
    objects = Object.objects.all()
    return render(request, 'accounts/objects.html', {'objects': objects})

#@login_required(login_url='login')
def employees(request):
    employees = Employee.objects.all()
    return render(request, 'accounts/employees.html', {'employees': employees})

#@login_required(login_url='login')
def legalentities(request):
    legalentities = LegalEntity.objects.all()
    return render(request, 'accounts/legalentities.html', {'legalentities': legalentities})

#@login_required(login_url='login')
def rooms(request):
    rooms = Room.objects.all()
    return render(request, 'accounts/rooms.html', {'rooms': rooms})

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def create_employee(request):
    employee = EmployeeForm()
    if request.method == 'POST':
        employee = EmployeeForm(request.POST)
        if employee.is_valid():
            employee.save()
            return redirect('employee')

    context = {'item': employee}
    return render(request, 'accounts/form_update.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def create_legalentity(request):
    legalentity = LegalentityForm()
    if request.method == 'POST':
        legalentity = LegalentityForm(request.POST)
        if legalentity.is_valid():
            legalentity.save()
            return redirect('legalentity')

    context = {'item': legalentity}
    return render(request, 'accounts/form_update.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator'])
def create_object(request):
    objects = ObjectForm()

    if request.method == 'POST':
        objects = ObjectForm(request.POST)
        if objects.is_valid():
            objects.save()
            return redirect('object')

    context = {'item': objects}
    return render(request, 'accounts/form_update.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def create_room(request):
    room = RoomForm()
    if request.method == 'POST':
        room = RoomForm(request.POST)
        if room.is_valid():
            room.save()
            return redirect('room')

    context = {'item': room}
    return render(request, 'accounts/form_update.html', context)

##############
#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def update_employee(request, pk):
    employee_id = Employee.objects.get(id=pk)
    employee = EmployeeForm(instance=employee_id)

    if request.method == 'POST':
        employee = EmployeeForm(request.POST, instance=employee_id)
        if employee.is_valid():
            employee.save()
            return redirect('employee')

    context = {'item': employee}
    return render(request, 'accounts/form_update.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def update_legalentity(request, pk):
    legalentity_id = LegalEntity.objects.get(id=pk)
    legalentity = LegalentityForm(instance=legalentity_id)

    if request.method == 'POST':
        legalentity = LegalentityForm(request.POST, instance=legalentity_id)
        if legalentity.is_valid():
            legalentity.save()
            return redirect('legalentity')

    context = {'item': legalentity}
    return render(request, 'accounts/form_update.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator'])
def update_object(request, pk):
    object_id = Object.objects.get(id=pk)
    object = ObjectForm(instance=object_id)
    if request.method == 'POST':
        object = ObjectForm(request.POST, instance=object_id)
        if object.is_valid():
            object.save()
            return redirect('object')

    context = {'item': object}
    return render(request, 'accounts/form_update.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def update_room(request, pk):
    room_id = Room.objects.get(id=pk)
    room = RoomForm(instance=room_id)
    if request.method == 'POST':
        room = RoomForm(request.POST, instance=room_id)
        if room.is_valid():
            room.save()
            return redirect('room')

    context = {'item': room}
    return render(request, 'accounts/form_update.html', context)

#################
#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def delete_employee(request, pk):
    employee_id = Employee.objects.get(id=pk)
    if request.method == 'POST':
        employee_id .delete()
        return redirect('employee')

    context = {'item': employee_id}
    return render(request, 'accounts/delete_employee.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def delete_legalentity(request, pk):
    legalentity_id = LegalEntity.objects.get(id=pk)
    if request.method == 'POST':
        legalentity_id.delete()
        return redirect('legalentity')

    context = {'item': legalentity_id}
    return render(request, 'accounts/delete_legalentity.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator'])
def delete_object(request, pk):
    object_id = Object.objects.get(id=pk)
    if request.method == 'POST':
        object_id.delete()
        return redirect('object')

    context = {'item': object_id}
    return render(request, 'accounts/delete_object.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator'])
def delete_room(request, pk):
    room_id = Room.objects.get(id=pk)
    if request.method == 'POST':
        room_id.delete()
        return redirect('room')

    context = {'item': room_id}
    return render(request, 'accounts/delete_room.html', context)

#################
#@unauthenticated_user
def register_page(request):
    form = CreateUserForm()
    if request.method == 'POST':
        form = CreateUserForm(request.POST)
        if form.is_valid():
            user = form.save()
            group = Group.objects.get(name='user')
            user.groups.add(group)

            return redirect('login')

    context = {'form': form}
    return render(request, 'accounts/register.html', context)

#@unauthenticated_user
def login_page(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')

        user = authenticate(request, username=username, password=password)

        if user is not None:
            login(request, user)
            group = user.groups.all()[0].name
            conn = connections[group]
            conn.connect()
            return redirect('home')
        else:
            messages.info(request, "invalid data")

    context = {}
    return render(request, 'accounts/login.html', context)


def logout_user(request):
    logout(request)
    return redirect('login')

def objectsid(request, pk):
    object_id = object.objects.get(id=pk)
    object = ObjectForm(instance=object_id)

    if request.method == 'POST':
        object = ObjectForm(request.POST, instance=object_id)
        if object.is_valid():
            object.save()
            return redirect('object')

    context = {'object': object}
    return render(request, 'accounts/form_employee.html', context)

#########

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator'])
def get_employee(request, pk):
    employee_id = Employee.objects.get(id=pk)
    employee = EmployeeForm(instance=employee_id)
    context = {'item': employee}
    return render(request, 'accounts/form_get.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator'])
def get_legalentity(request, pk):
    legalentity_id = LegalEntity.objects.get(id=pk)
    legalentity = LegalentityForm(instance=legalentity_id)
    context = {'item': legalentity}
    return render(request, 'accounts/form_get.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator', 'user'])
def get_object(request, pk):
    object_id = Object.objects.get(id=pk)
    object = ObjectForm(instance=object_id)
    context = {'item': object}
    return render(request, 'accounts/form_get.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator', 'user'])
def get_room(request, pk):
    room_id = Room.objects.get(id=pk)
    room = RoomForm(instance=room_id)
    context = {'item': room}
    return render(request, 'accounts/form_get.html', context)

#@login_required(login_url='login')
#@allowed_users(allowed_roles=['administrator', 'moderator', 'user'])
def get_qr_object(request, pk):
    object_id = Object.objects.get(id=pk)
    object = ObjectForm(instance=object_id)

    context = {'item': object}
    return render(request, 'accounts/form_get.html', context)