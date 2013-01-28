#!/usr/bin/env python

import sys
from PIL import Image

if __name__ == "__main__":
    assert len(sys.argv) > 1 
    
    image = Image.open(sys.argv[1])
    w, h = image.size

    color_counts = {}
    for x in range(w):
        for y in range(h):
            pixel = image.getpixel((x, y))
            if pixel not in color_counts:
                color_counts[pixel] = 0
            color_counts[pixel] += 1

    sorted_color_counts = color_counts.items()
    sorted_color_counts.sort(key = lambda cnt: cnt[1])
    for color_count in sorted_color_counts:
        print hex(color_count[0][0]), hex(color_count[0][1]), hex(color_count[0][2]), color_count[1]
        print color_count
