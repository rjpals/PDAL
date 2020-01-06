
import laspy
from numcodecs import Blosc
import zarr

f = laspy.file.File('../../../../test/data/las/1.2-with-color.las')

data = f.points['point']

compressor = Blosc(cname='zstd', clevel=3, shuffle=Blosc.BITSHUFFLE)

z = zarr.array(data, chunks=(10), compressor=compressor)

zarr.save('1.2-with-color-zstd.zarr', z)

print (z.info)
