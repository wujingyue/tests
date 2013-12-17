import sys
import hashlib
import zlib
import struct

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as f:
        assert len(f.read(32)) == 32
        sig = hashlib.sha1()
        while True:
            buf = f.read(1024)
            if buf == '':
                break
            sig.update(buf)
    with open(sys.argv[1], 'r') as f:
        f.read(12)
        filled_sig = f.read(20)
    print sig.digest() == filled_sig

    with open(sys.argv[1], 'r') as f:
        assert len(f.read(12)) == 12
        checksum = zlib.adler32('')
        while True:
            buf = f.read(1024)
            if buf == '':
                break
            checksum = zlib.adler32(buf, checksum)
    with open(sys.argv[1], 'r') as f:
        f.read(8)
        filled_checksum = f.read(4)
    print struct.pack('i', checksum) == filled_checksum
