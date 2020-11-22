Multi-threading
```python
import concurrent
with concurrent.futures.ThreadPoolExecutor(max_workers=2) as executor: 
    _ = {executor.submit(cov.sifts_get_database_version_by_pdbid, pdbid): pdbid for pdbid in pdbids}
    for future in concurrent.futures.as_completed(_):
        pdbid = _[future]
        try:
            db_ver = future.result()
        except Exception as exc: # exception from func when result is called.
            print(pdbid)
        else:
            print(f'"{pdbid}": "{db_ver}",')
```
