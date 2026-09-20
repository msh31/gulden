#include "chain/block.hpp"

auto gchain::hash_block(const Block& block) -> Hash {
	std::string h{};

	auto ph = std::to_string(block.previous_hash);
	auto t = std::to_string(block.timestamp);

	h = ph + "|" + t + "|" + block.payload;

	return std::hash<std::string>{}(h);
}

auto gchain::make_block(Hash h, const std::string& payload) -> Block {
	Block b{};
	b.previous_hash = h;

	auto now = std::chrono::system_clock::now();
	auto secs = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	b.timestamp = secs.count();

	b.payload = payload;
	b.current_hash = hash_block(b);

	return b;
}