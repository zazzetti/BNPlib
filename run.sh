g++ -D_REENTRANT \
	-I ./stan-math/lib/eigen_3.3.3 \
	-I ./stan-math/lib/tbb_2019_U8/include/ \
	-I ./stan-math/lib/sundials_4.1.0/include/ \
	-o test.o test_main.cpp

#/home/bruno/Desktop/bnplib/stan-math/
