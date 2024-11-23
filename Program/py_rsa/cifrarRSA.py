# Librerías de Crypto
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

# Abre el archivo que contiene la llave pública y la carga
def cargar_llave_rsa(file_path):
    with open(file_path, 'rb') as file:
        key = RSA.import_key(file.read())
    return key

# Lee el archivo y cifra el contenido con la llave pública
def cifrar_archivo_rsa(archivo_path, llave_publica_path, output_path):
    with open(archivo_path, 'rb') as file:
        archivo_data = file.read()

    llave_publica = cargar_llave_rsa(llave_publica_path)
    cifrador = PKCS1_OAEP.new(llave_publica)
    archivo_cifrada = cifrador.encrypt(archivo_data)

    with open(output_path, 'wb') as file:
        file.write(archivo_cifrada)

# Ruta de archivo a cifrar
mensaje_path = 'mensaje.txt'

# Ruta para crear archivo cifrado
llave_publica_path = '../llaves/llave_publica_diego.pem'

# Ruta para crear archivo cifrado
output_path = 'archivo_cifrado.bin'

cifrar_archivo_rsa(mensaje_path, llave_publica_path, output_path)
