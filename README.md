### Simple WEB SERVER 
-
Este código le permite al ESP32 crear un web server que servirá un página web.
El ESP32 esta programado para conectarse a una red WiFi.

```
const char* ssid = "noShar3";
const char* password = "holacomoestas";
```
Esta sección del código es dónde se debe ingresar las credenciales de la red WIFI a la que deseo conectarme.
-
Luego de conectarse a la red WIFI, el ESP32 nos da una dirección IP a través del monitor serial, que es a la que debemos acceder desde el navegador para visualizar la página web.