### 百度小程序 用户数据的签名验证和加解密 解密示例代码 (Python)
```
# pip install pycrypto 
import struct
from base64 import b64decode
from Crypto.Cipher import AES 

def decrypt(ciphertext, iv, app_key, session_key):
    aes_key     = b64decode(session_key)
    iv          = b64decode(iv) 
    ciphertext  = b64decode(ciphertext)
    
    cipher      = AES.new(aes_key, AES.MODE_CBC, iv)
    plaintext   = cipher.decrypt(ciphertext)
    
    # trim pkcs#7 padding
    pad         = plaintext[-1]
    pad         = 0 if (pad < 1 or pad > 32) else pad
    plaintext   = plaintext[:len(plaintext)-pad] 
    
    # trim header
    plaintext   = plaintext[16:] 
    # get content length
    content_len = struct.unpack(">L",plaintext[:4])[0]
    # get content
    content     = plaintext[4:content_len+4] 
    # get app_key
    app_key_decode = plaintext[content_len+4:].decode() 
    return content.decode() if app_key_decode == app_key else False

ciphertext  = "OpCoJgs7RrVgaMNDixIvaCIyV2SFDBNLivgkVqtzq2GC10egsn+PKmQ/+5q+chT8xzldLU\
og2haTItyIkKyvzvmXonBQLIMeq54axAu9c3KG8IhpFD6+ymHocmx07ZKi7eED3t0KyIxJgRNSDkFk5RV1ZP2\
mSWa7ZgCXXcAbP0RsiUcvhcJfrSwlpsm0E1YJzKpYy429xrEEGvK+gfL+Cw==";  # 待解密数据，返回的内容中的data字段
iv          = "1df09d0a1677dd72b8325Q==";                        # 加密向量，返回的内容中的iv字段
app_key     = "y2dTfnWfkx2OXttMEMWlGHoB1KzMogm7";                # 创建小程序时生成的app_key
session_key = "1df09d0a1677dd72b8325aec59576e0c";                # 登录的code换得的 # AES_Key

decrypt(ciphertext, iv, app_key, session_key)
# 解密结果应该是 '{"openid":"open_id","nickname":"baidu_user","headimgurl":"url of image","sex":1}'
```
