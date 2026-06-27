# LMF

Build LMF:
```sh
rm -rf build && meson setup build
ninja -C build
```

Run LMF (prerequisites: 5G-core):
```sh
./build/src/lmf/lmfd -c build/configs/lmf.yaml
```
