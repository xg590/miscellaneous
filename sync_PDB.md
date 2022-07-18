```python3
# pip install bs4 biopython

rcsb_cif_gz_dir = '/scratch/xg590/source/rcsb_cif_gz'
rcsb_cif_dir    = '/scratch/xg590/source/rcsb_cif' 

import os, pathlib, subprocess, multiprocessing 
_ = [pathlib.Path(i).mkdir(parents=True, exist_ok=True) 
        for i in [rcsb_cif_gz_dir, rcsb_cif_dir, cpd_cif, adduct_bin]] 

from IPython.core.display import display, HTML, SVG, clear_output
display(HTML("<style>.container { width:100% !important; }</style>")) 

import io, urllib, Bio.PDB, sys, pickle, math, json, re#, bs4
from rdkit import Chem
from rdkit.Chem import AllChem, PandasTools
PandasTools.RenderImagesInAllDataFrames(images=True)
from rdkit.Chem.Draw import IPythonConsole  
from rdkit.Geometry.rdGeometry import Point3D

class PDB_Cov_Exception(Exception):
    def __init__(self, msg=None):
        Exception.__init__(self, msg) 

## Mirror The DB 
def mirror_db():
    subprocess.run(f"rsync -rlpt -z --delete --port=33444 rsync.rcsb.org::ftp_data/structures/divided/mmCIF/ {rcsb_cif_gz_dir}", shell=True)
    
    from urllib.request import urlopen
    obsolete = 'ftp://ftp.wwpdb.org/pub/pdb/data/status/obsolete.dat'
    with urlopen(obsolete) as fr:
        _ = fr.readline()
        while True:
            try:
                line = fr.readline().decode()
                if not line: break
                PDBID = line.split()[2]
                pdbid = PDBID.lower()  
                os.remove(f'{rcsb_cif_dir}/{pdbid[1:3]}/{pdbid}.cif') 
                print('{} is now obselete and deleted successfully.'.format(PDBID))
            except Exception as e:
                print(e) 
                
#mirror_db()

## Decompress
def unzipper(pdb_id):
    cif_subdir = f'{rcsb_cif_dir}/{pdb_id[1:3]}'
    pathlib.Path(cif_subdir).mkdir(parents=True, exist_ok=True)
    cif        = f'{rcsb_cif_dir}/{pdb_id[1:3]}/{pdb_id}.cif'
    if os.path.isfile(cif): return None
    gz         = f'{rcsb_cif_gz_dir}/{pdb_id[1:3]}/{pdb_id}.cif.gz'
    proc = subprocess.run(args=['gzip', '-dc', gz], stdout=subprocess.PIPE) # unzip the zipped 
    with open(cif, 'wb') as fw: fw.write(proc.stdout)   

def decompress():
    pdb_ids = []
    for subdir in os.scandir(rcsb_cif_gz_dir): 
        if subdir.is_dir():
            for gz in os.scandir(subdir.path):
                if gz.is_file():
                    pdb_ids.append(gz.name[:4])
    
    with multiprocessing.Pool(multiprocessing.cpu_count()) as p: # unzipping in 3 cores  
        p.map(unzipper, pdb_ids, multiprocessing.cpu_count()) 
        
#decompress()
```
