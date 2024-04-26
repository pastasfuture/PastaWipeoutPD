#include "system.h"
#include "render.h"
#include "platform.h"
#include "mem.h"
#include "utils.h"

#include "wipeout/game.h"

static double time_real;
static double time_scaled;
static double time_scale = 1.0;
static double tick_last;
static double cycle_time = 0;

void system_init(PlaydateAPI* pd, uint8_t scale, float target_fps) {
	pd->display->setRefreshRate(target_fps);
	render_init(pd, scale);
	game_init(pd);
}

void system_update(PlaydateAPI* pd, float target_fps, bool draw_scenery) {
	double time_real_now = pd->system->getElapsedTime();
	double real_delta = time_real_now - time_real;
	time_real = time_real_now;
	tick_last = min(real_delta, 0.1) * time_scale;
	time_scaled += tick_last;
	
	
	
	
	// double real_delta = 1.0 / target_fps;
	// time_real += real_delta;
	// tick_last = min(real_delta, 0.1) * time_scale;
	// time_scaled += tick_last;

	// FIXME: come up with a better way to wrap the cycle_time, so that it
	// doesn't lose precision, but also doesn't jump upon reset.
	cycle_time = time_scaled;
	if (cycle_time > 3600 * M_PI) {
		cycle_time -= 3600 * M_PI;
	}
	
	render_frame_prepare(pd);
	game_update(pd, draw_scenery);
}

void system_reset_cycle_time(void) {
	cycle_time = 0;
}

void system_resize(PlaydateAPI* pd, uint8_t scale) {
	render_set_screen_size(pd, scale);
}

double system_time_scale_get(void) {
	return time_scale;
}

void system_time_scale_set(double scale) {
	time_scale = scale;
}

double system_tick(void) {
	return tick_last;
}

double system_time(void) {
	return time_scaled;
}

double system_cycle_time(void) {
	return cycle_time;
}
