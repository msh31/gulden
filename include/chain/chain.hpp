#pragma once
#include "block.hpp"

class CChain {
	public:
		CChain() {
			m_blocks.emplace_back(gchain::make_block(0, "genesis"));
		}

		auto append(const std::string& payload) -> void;
		auto validate() const -> bool;

		const std::vector<gchain::Block>& get_blocks() const {
			return m_blocks;
		}

	private:
		std::vector<gchain::Block> m_blocks;
};