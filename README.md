# What The Duck - Version client

## Pour commencer

Cloner le projet **récursivement** *(pour récupérer la version cliente et serveur)* !

`git clone https://github.com/Lucassky10/WhatTheDuckClient --recursive`

## Prérequis

[Debian] Bibliothèque requises

`g++ mesa-utils libglew-dev libglfw3-dev libsdl2-dev libsdl2-image-dev libopenal-dev libalut-dev freeglut3-dev libjsoncpp-dev`

## Exécuter le projet

**Phase de compilation**

*Client*

`cd WhatTheDuckClient`

`make cleanalllibs && make main`

*Serveur*

`cd WhatTheDuckServer`

`make cleanalllibs && make main`

**Phase de lancement**

1. Lancer le serveur

`cd WhatTheDuckServer`

`make run`

2. Lancement des clients

`cd WhatTheDuckClient`

`make run`

...

`make run`