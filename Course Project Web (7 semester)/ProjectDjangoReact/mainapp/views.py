from django.shortcuts import render


def index(request):
    return render(request, 'index.html', {})


def rooms(request):
    return render(request, 'index.html', {})

def room_select(request, id):
    return render(request, 'index.html', {})

def room_edit(request, id):
    return render(request, 'index.html', {})


def room_add(request):
    return render(request, 'index.html', {})


def objects(request):
    return render(request, 'index.html', {})

def object_select(request, id):
    return render(request, 'index.html', {})

def object_edit(request, id):
    return render(request, 'index.html', {})


def object_add(request):
    return render(request, 'index.html', {})


def legalentities(request):
    return render(request, 'index.html', {})

def legalentity_select(request, id):
    return render(request, 'index.html', {})

def legalentity_edit(request, id):
    return render(request, 'index.html', {})


def legalentity_add(request):
    return render(request, 'index.html', {})


def employees(request):
    return render(request, 'index.html', {})

def employee_select(request, id):
    return render(request, 'index.html', {})

def employee_edit(request, id):
    return render(request, 'index.html', {})

def employee_add(request):
    return render(request, 'index.html', {})
