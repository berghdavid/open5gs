# ASN1

Clone the currently active ASN1C repo to somewhere on your disk (not within the LMF repo):
```sh
git clone https://github.com/mouse07410/asn1c
```

Follow instructions in `asn1c/INSTALL.md`

Compile ASN1 files:
```sh
asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER -D ./gen/ specs/19.1.0/NRPPA-*.asn
```
