

## Установка и запуск
Проект не имеет внешних зависимостей и собирается на любой POSIX-системе.

**1. Подготовка:**
- **Linux:** `sudo apt update && sudo apt install build-essential git`
- **Termux:** `pkg update && pkg install clang make git`

**2. Сборка и запуск:**
```bash
# 1. Клонируем и заходим в папку
git clone https://github.com
cd PROJECT_NAME

# 2. Компилируем и даем права (критично для Termux)
clang main.c -o my_utility || gcc main.c -o my_utility
chmod +x my_utility

# 3. Запускаем
./my_utility

Либо через Makefile:
Если вы используете make, просто введите:
make

Для справки: Содержимое файла Makefile
Если ты хочешь, чтобы команда make работала, создай рядом с main.c файл с именем Makefile и таким текстом:

all:
	clang main.c -o my_utility || gcc main.c -o my_utility
	chmod +x my_utility
```
