#include <chain/chain.hpp>

void CChain::append(const std::string& payload) {
	auto lbch = m_blocks.back().current_hash;
	m_blocks.emplace_back(gchain::make_block(lbch, payload));
}