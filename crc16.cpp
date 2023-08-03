QString crc16(QString source)
{
    ushort crc = 65535;
    ushort polynomial = 4129;
    int length = source.length();
    int i = 0;

    while (length > 0) {
        crc ^= source[i].toLatin1() << 8;
        crc &= 0xFFFF;
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ polynomial;
            } else {
                crc = crc << 1;
            }
            crc &= 0xFFFF;
        }
        length -= 1;
        i += 1;
    }
    return QString::number(crc);
}
