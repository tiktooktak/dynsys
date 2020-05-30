# Моделирование и визуализация динамических систем

![Аттрактор Хедли](https://github.com/kkarnauk/dynsys/blob/main/media/Hadley.gif)

## Введение

Есть системы дифференциальных уравнений первого порядка на координаты, которые описывают положение точек в пространстве с течением времени. Наше приложение моделирует их, позволяя удобно исследовать данную область.

В частности, приложение уже содержит 35 систем, моделирующих классические странные аттракторы.

Примеры систем уравнений: [Аттрактор Лоренца](https://ru.wikipedia.org/wiki/%D0%90%D1%82%D1%82%D1%80%D0%B0%D0%BA%D1%82%D0%BE%D1%80_%D0%9B%D0%BE%D1%80%D0%B5%D0%BD%D1%86%D0%B0) и [Аттрактор Рёсслера](https://ru.wikipedia.org/wiki/%D0%90%D1%82%D1%82%D1%80%D0%B0%D0%BA%D1%82%D0%BE%D1%80_%D0%A0%D1%91%D1%81%D1%81%D0%BB%D0%B5%D1%80%D0%B0)

## Интерфейс

Интерфейс реализован с помощью Qt5. Включает в себя:
* Выбор модели
* Выбор констант, характеризующих модель
* Детальные настройки моделирования и визуализации
* Возможность записи видео
* Возможность паузы и перематывания времени

![Снимок интерфейса](https://github.com/kkarnauk/dynsys/blob/main/media/Interface.png) 

## Моделирование

Моделирование производится с помощью метода Рунге-Кутты четвертого порядка точности, с постоянным шагом. Написано в стиле метапрограммирования, чтобы достичь максимальной производительности.

Для возможности поддержки моделей, которые не интегрированы в приложение, реализован парсер математических уравнений, который поддерживает стандартные операции (+ - \* /), скобки и основные математические функции (sin, cos, exp, log и т.д.).

Для вычислений не используются никакие дополнительные библиотеки.

## Визуализация

Визуализация производится при помощи OpenGL (версия 3.3) и обертки Qt над ним.

Приложение берёт несколько точек около изначальной позиции, считает их траектории и затем отображает точки с некоторым хвостом их траектории. Точки, посчитанные моделью, интерполируются кривой Катмулл-Рома.

Реализована воможность свободного перемещения.

Для удобства есть возможность записи видео в формате avi. Для этого используется библиотека libav (ffmpeg 4.2.2). Также можно делать снимки экрана.

## Поддержка OS

Приложение поддерживается следующими операционными системами:
* Linux
* Windows
* MacOS

## Инструкция по установке

Замечание: данная инструкция действительна для Linux Ubuntu 18.04.

* Установка Qt:
```
sudo add-apt-repository ppa:beineri/opt-qt-5.12.0-bionic
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install qt5-default qt512base qt512imageformats qt512svg5
```

* Установка libav (ffmpeg):
```
sudo add-apt-repository ppa:mc3man/xerus-media
sudo apt-get update
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libavutil-dev
```

* Обновление OpenGL:
```
sudo add-apt-repository ppa:oibaf/graphics-drivers
sudu apt-get update
sudo apt-get install libgl1-mesa-dev libegl1-mesa xserver-xorg-video-intel libgl1-mesa-dri libglapi-mesa
```

## Как использовать?

Чтобы визуализировать модель, необходимо:

* Выбрать модель, которую необходимо смоделировать:
    * Можно выбрать одну из 35 представленных моделей
    * Можно ввести свои собственные дифференциальные уравнения
* Выбрать константы, которые характеризуют модель:
    * Можно выбрать классические значения
    * Можно ввести собственные значения
* Выставить необходимые настройки:
    * Настройки камеры:
    * Настройки моделирования:
    * Настройки визуализации:

Управление:
* `WASDQE` — перемещение вперед / вправо / вниз / влево / вверх / вниз

* `F` — вернуться в изначальное положение
* `R` — сделать снимок экрана

## Примеры

![Аттрактор Декуан Ли](https://github.com/kkarnauk/dynsys/blob/main/media/Dequan%20Li.gif)

![Пример 1](https://github.com/kkarnauk/dynsys/blob/main/media/Example1.png) 

![Пример 2](https://github.com/kkarnauk/dynsys/blob/main/media/Example2.png) 

## Ссылки

Каналы:
* [YouTube](https://www.youtube.com/channel/UCL6pzFtbNd7fZKhABJCvV8g?view_as=subscriber)

* [Telegram](https://t.me/strangeattractors)

## О нас

Приложение пишется в рамках проектной работы в НИУ ВШЭ СПб.

Авторы: [Носивской Владислав](https://github.com/vladnosiv), [Венедиктов Роман](https://github.com/e2e4b6b7), [Карнаухов Кирилл](https://github.com/kkarnauk)
