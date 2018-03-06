#adapted from https://github.com/python/cpython/blob/2.7/Lib/heapq.py

class StateHeap(object):
    def __init__(self):
        self.heap = []
        
    def cmp_lt(self, x, y):
        # Use __lt__ if available; otherwise, try __le__.
        # In Py3.x, only __lt__ will be called.
        a = x.heuristic()
        b = y.heuristic()
        return a < b

    def _siftdown(self, startpos, pos):
        heap = self.heap
        newitem = heap[pos]
        # Follow the path to the root, moving parents down until finding a place
        # newitem fits.
        while pos > startpos:
            parentpos = (pos - 1) >> 1
            parent = heap[parentpos]
            if self.cmp_lt(newitem, parent):
                heap[pos] = parent
                pos = parentpos
                continue
            break
        heap[pos] = newitem

    def _siftup(self, pos):
        heap = self.heap
        endpos = len(heap)
        startpos = pos
        newitem = heap[pos]
        # Bubble up the smaller child until hitting a leaf.
        childpos = 2*pos + 1    # leftmost child position
        while childpos < endpos:
            # Set childpos to index of smaller child.
            rightpos = childpos + 1
            if rightpos < endpos and not self.cmp_lt(heap[childpos], heap[rightpos]):
                childpos = rightpos
            # Move the smaller child up.
            heap[pos] = heap[childpos]
            pos = childpos
            childpos = 2*pos + 1
        # The leaf at pos is empty now.  Put newitem there, and bubble it up
        # to its final resting place (by sifting its parents down).
        heap[pos] = newitem
        self._siftdown(startpos, pos)

    def heappush(self, item):
        """Push item onto heap, maintaining the heap invariant."""
        heap = self.heap
        heap.append(item)
        self._siftdown(0, len(heap)-1)

    def heappop(self):
        """Pop the smallest item off the heap, maintaining the heap invariant."""
        heap = self.heap
        lastelt = heap.pop()    # raises appropriate IndexError if heap is empty
        if heap:
            returnitem = heap[0]
            heap[0] = lastelt
            self._siftup(0)
        else:
            returnitem = lastelt
        return returnitem

    def empty(self):
        return len(self.heap) == 0
