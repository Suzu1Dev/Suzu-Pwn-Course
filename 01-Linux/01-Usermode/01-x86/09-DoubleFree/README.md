## How to run?
```
docker-compose up -d --build
nc localhost 1337
```

this might solve problems in WSL:
```
PYTHONPATH=/usr/lib/python3/dist-packages docker-compose up -d --build
```