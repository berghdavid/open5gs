# LMF

Build LMF:
```sh
rm -rf build && meson setup build
ninja -C build
```

Run LMF (prerequisites: 5G-core):
```sh
./build/src/lmf/open5gs-lmfd -c build/configs/open5gs/lmf.yaml
```
