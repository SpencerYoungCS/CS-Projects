#ifndef CH13ZIPCODE_H
#define CH13ZIPCODE_H

class ZipCode
{
public:
    ZipCode();
    ZipCode(int zip);
    ZipCode(char barcode[]);

    int convertzip(char barcode[]);
    char convertbarcode(int zip);

    int setzip(int converted);
    int getzip();

    int error();

private:
    int zip;
};

#endif // CH13ZIPCODE_H
