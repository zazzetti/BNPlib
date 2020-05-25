#!/usr/bin/python
from bnp_interface import *

mu0 = 0.0
lambda_ = 0.1
alpha0 = 2.0
beta0 = 2.0
totalmass = "TODO"
algo = "neal2"
algoDL = ''.join((algo, '_dataless'))
rng = 20200229
maxit = 10000
burn = 1000
colltype = "file"
only = "all"

grid1 = np.arange(-5, +5, 0.5)
grid2 = np.arange(-7, +7, 0.5)
grid3 = np.arange(-4, +4, 0.5)
grid4 = "TODO"
# or linspace

for i in range(1,5):
	print("Starting test", i)

	# Write file names
	datafile  = ''.join(("csv/test/data", i, ".csv"))
	collfile  = ''.join(("collector", i, ".recordio"))
	densfile  = ''.join(("src/python/test_res/dens",  i, ".csv"))
	clustfile = ''.join(("src/python/test_res/clust", i, ".csv"))
	imgfileclust = ''.join(("src/python/test_res/clust", i, ".pdf"))
	imgfilechain = ''.join(("src/python/test_res/chain", i, ".pdf"))
	imgfiledens  = ''.join(("src/python/test_res/dens",  i, ".pdf"))
	bnplibpy.run_NNIG_Dir(mu0, lambda_, alpha0, beta0, totalmass, datafile,
		algo, colltype, collfile, rng, maxit, burn)

	chain_histogram(collfile, imgfilechain)
	
	bnplibpy.estimates_NNIG_Dir(mu0, lambda_, alpha0, beta0, totalmass, grid,
		algoDL, collfile, densfile, clustfile, only)

	plot_clust_cards(clustfile, imgfileclust)
	plot_density(densfile, imgfiledens)


print("The end")