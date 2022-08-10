make
rm error.log
touch error.log
rm cat_*
#file type error
./mip -i cat.txt -o cattt.ppm -t verticalFlip >> error.log

#file name error
./mip -i cat2.ppm -o cattt.ppm -t verticalFlip >> error.log

#transformation name error
./mip -i cat.ppm -o cattt.ppm -t verticalFlippp >> error.log
./mip -i cat.ppm -o cattt.ppm -t intensityInversian >> error.log

#help
./mip -i cat.ppm -o cattt.ppm -t intensityInversian -h >> error.log
./mip -i cat.ppm -o cattt.ppm -t intensityInversian --help >> error.log 
./mip -h >> error.log

#transform
./mip -i cat.ppm -o cat_verti.ppm -t verticalFlip
./mip -i cat.ppm -o cat_rotate.ppm -t rotate90
./mip -i cat.ppm -o cat_intens.ppm -t intensityInversion
./mip -i cat.ppm -o cat_max.ppm -t maxFilter
./mip -i cat.ppm -o cat_mean.ppm -t meanFilter
./mip -i cat.ppm -o cat_median.ppm -t medianFilter
