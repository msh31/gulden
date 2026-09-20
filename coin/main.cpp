#include <chain/chain.hpp>

auto main() -> int {
    CChain chain;
    chain.append("one");
    chain.append("two");
    chain.append("three");

    const auto& blocks = chain.get_blocks();
    for (const auto& b : blocks) {
        std::println("previous hash: {}", b.previous_hash);
        std::println("current hash: {}", b.current_hash);
        std::println("timestamp: {}", b.timestamp);
        std::println("payload: {}", b.payload);
    }

    return 0;
}
