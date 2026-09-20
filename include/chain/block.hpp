#pragma once

namespace gchain {
	using Hash = std::size_t;

	struct Block {
		Hash previous_hash;
		std::int64_t timestamp;
		std::string payload;
		Hash current_hash;
	};

	auto hash_block(const Block& block) -> Hash;
	auto make_block(Hash h, const std::string& payload) -> Block;
}