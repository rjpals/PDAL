
import laspy
from numcodecs import Blosc
import zarr

f = laspy.file.File('../las/1.2-with-color.las')

data = f.points['point']

compressor = Blosc(cname='zstd', clevel=3, shuffle=Blosc.BITSHUFFLE)

z = zarr.array(data, chunks=(10), compressor=compressor)

root = zarr.open('1.2-with-color-zstd.zarr', mode='w')
group = root.create_group('las')
group.create_dataset('1.2-with-color', data=data, overwrite=True)

print (z.info)
