# Librerías de Crypto
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

# Abre el archivo que contiene la llave pública y la carga
def cargar_llave_rsa(file_path):
    with open(file_path, 'rb') as file:
        key = RSA.import_key(file.read())
    return key

# Lee el archivo cifrado y descifra el contenido con la llave privada
def desencriptar_archivo_rsa(archivo_cifrada_path, llave_privada_path, output_path):
    with open(archivo_cifrada_path, 'rb') as file:
        archivo_cifrada = file.read()

    llave_privada = cargar_llave_rsa(llave_privada_path)
    descifrador = PKCS1_OAEP.new(llave_privada)
    archivo_descifrada = descifrador.decrypt(archivo_cifrada)

    with open(output_path, 'wb') as file:
        file.write(archivo_descifrada)

# Ruta de archivo cifrado
archivo_cifrada_path = 'menseje_cifrada.bin'

# Ruta de llave privada
llave_privada_path = '../llaves/llave_privada.pem'

# Ruta para crear archivo descifrado
output_path = 'archivo_descifrada.txt'

desencriptar_archivo_rsa(archivo_cifrada_path, llave_privada_path, output_path)
