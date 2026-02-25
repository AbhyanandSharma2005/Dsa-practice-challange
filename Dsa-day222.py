class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        bit_freq = defaultdict(list)

        for num in arr:
            binary = bin(num)
            bit_cnt = binary.count("1")
            bit_freq[bit_cnt].append(num)

        ordered_dict = OrderedDict(sorted(bit_freq.items()))

        ans_lst = []
        for value in ordered_dict.values():
            ans_lst.extend(sorted(value))

        return ans_lst