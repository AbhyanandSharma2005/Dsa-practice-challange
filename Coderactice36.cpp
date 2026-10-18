namespace {
constexpr unsigned modulo = 1'000'000'007;
constexpr unsigned max_size = 1000;
constexpr void imul_mod(unsigned& x, unsigned y) noexcept {
    x = (x * (unsigned long long) y) % modulo;
}
constexpr unsigned pow_mod(unsigned base, unsigned exponent) noexcept {
    unsigned result = 1;
    base %= modulo;
    while (exponent) {
        if (exponent % 2u == 1u)
            imul_mod(result, base);
        imul_mod(base, base);
        exponent /= 2;
    }
    return result;
}
constexpr void idiv_mod(unsigned& x, unsigned y) noexcept {
    // Modulo is prime, use Fermat's Little Theorem
    imul_mod(x, pow_mod(y, modulo - 2u));
}

struct Solution {
    static int numOfWays(std::span<int> nums) noexcept {
        unsigned result = 1;
        for (unsigned i = 1; i <= nums.size(); ++i)
            imul_mod(result, i);
        unsigned divisor = 1;
        std::span<int> stack[std::bit_width(max_size)-1u];
        std::span<int>* stack_end = stack;
        *stack_end++ = nums;
        while (stack_end != stack) {
            std::span<int> top = *--stack_end;
            if (top.size() <= 1u)
                continue;

            imul_mod(divisor, top.size());

            static int temp[max_size-1u];
            int* left_storage = std::begin(temp);
            int* right_storage = std::end(temp);

            // Partition by < pivot and > pivot
            int pivot = top.front();
            top = top.subspan(1);
            for (int i : top)
                *(i < pivot ? left_storage++ : --right_storage) = i;

            auto mid = std::copy(std::begin(temp), left_storage, top.begin());
            std::copy(std::rbegin(temp), std::make_reverse_iterator(right_storage), mid);

            std::span<int> left(top.begin(), mid);
            std::span<int> right(mid, top.end());

            if (left.size() > right.size())
                std::swap(left, right);  // Visit smaller side first to limit stack depth

            *stack_end++ = right;
            if (!left.empty())
                *stack_end++ = left;
        }
        idiv_mod(result, divisor);
        return result - 1u;
    }
};
}