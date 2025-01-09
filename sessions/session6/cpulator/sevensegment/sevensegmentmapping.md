[Main Menu](../../../README.md) | [session6](../../../session6/) | [Seven Segment Mapping](../sevensegment/sevensegmentmapping.md)

## Mapping of registers to 7 segment displays in CPUlator

https://www-ug.eecg.utoronto.ca/desl/nios_devices_SoC/ARM/dev_7segs.html

c example
```
#define ADDR_7SEG1 ((volatile long *) 0xFF200020)
#define ADDR_7SEG2 ((volatile long *) 0xFF200030)

int main()
{
   // bits 0000110 will activate segments 1 and 2 
   *ADDR_7SEG1 = 0x00000006; 
   *ADDR_7SEG2 = 0;
}
```


A [seven segment display](https://en.wikipedia.org/wiki/Seven-segment_display) uses 7 lines to display numbers and letters
 
The following bit patterns set the values of the 7 segment display in CPUlator

```

                      0b0000001 (0x01)
                    **************
                    *            *
   0b0100000 (0x20) *            * 0b0000010 (0x02)
                    *    (0x40)  *
                    * 0b1000000  *
                    **************
                    *            *
   0b0010000 (0x10) *            * 0b0000100 (0x04)
                    *            *
                    *            *
                    **************
                      0b0001000 (0x08)
             
```

# 7 segment numbers

list (0-f) 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71

### Zero 0
```
0b0111111 (0x3F)
   _
  | |
  |_|

```
### One 1
```
0b0000110 (0x06)

    |
    |

```

### Two 2

```
0b1011011 (0x5B)
   _
   _|
  |_

```

### Three 3

```
0b1001111 (0x4F)
   _
   _|
   _|

```

### Four 4

```
0b1100110 (0x66)
   
  |_|
    |

```

### Five 5
```
0b1101101 (0x6D)
   _
  |_
   _|

```

### six 6

```
0b1111101 (0x7D)
   _
  |_
  |_|

```

### Seven 7

```
0b0000111 (0x07)
   _
    |
    |

```

### Eight 8

```
0b1111111 (0x7F)
   _
  |_|
  |_|

```

### Nine 9

```
0b1101111(0x6F)
   _
  |_|
   _|

```

### hex A

```
0b1110111 (0x77)
   _
  |_|
  | |

```

### hex B

```
0b1111100 (0x7c)
   
  |_
  |_|

```

### hex c

```
0b0111001 (0x39)
   _
  |
  |_

```

### hex d

```
0b1011110 (0x5E)
   
   _|
  |_|

```

### hex e

```
0b1111001 (0x79)
   _
  |_
  |_

```

### hex f

```
0b1111001 (0x71)
   _
  |_
  |

```

## seven segments (with one segment off)

```
0b1111111
   _
  |_|
  |_|

```

```
0b0111111
   _
  | |
  |_|

```

```
0b1011111
   _
   _|
  |_|

```

```
0b1101111
   _
  |_|
   _|

```

```
0b1110111
   _
  |_|
  | |

```

```
0b1111011
   _
  |_|
  |_

```

```
0b1111101
   _
  |_
  |_|

```

```
0b1111110
   
  |_|
  |_|
  
```
