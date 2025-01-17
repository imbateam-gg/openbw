#pragma once

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#include "titan-reactor.h"
#include "common.h"
#include "bwgame.h"
#include "replay.h"

#include <chrono>
#include <thread>

struct saved_state
{
	bwgame::state st;
	bwgame::action_state action_st;
	std::array<bwgame::apm_t, 12> apm;
};

struct main_t
{
	bwgame::titan_replay_functions ui;

	main_t(bwgame::game_player player) : ui(std::move(player)) {}

	std::chrono::high_resolution_clock clock;
	std::chrono::high_resolution_clock::time_point last_tick;

	std::chrono::high_resolution_clock::time_point last_fps;
	int fps_counter = 0;

	bwgame::a_map<int, std::unique_ptr<saved_state>> saved_states;
	bool run_main_update_loop = true;

	void reset();
	void next_frame();
	void update();
};
