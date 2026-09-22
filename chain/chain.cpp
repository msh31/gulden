#include <chain/chain.hpp>

auto CChain::append(const std::string& payload) -> void {
	auto lbch = m_blocks.back().current_hash;
	m_blocks.emplace_back(gchain::make_block(lbch, payload));
}

auto CChain::validate() const -> bool {
	if (m_blocks.empty()) {
		return false;
	}

	for (size_t i = 1; i < m_blocks.size(); ++i) {
		auto recomputed_hash = gchain::hash_block(i);
		auto current_hash = b.current_hash;

		if (recomputed_hash != current_hash) {
			return false;
		}

		if (b.previous_hash == 0) {
			//genesis
			continue;
		}

		if (b.previous_hash != current_hash) {
			return false;
		}
	}


	return true;
}