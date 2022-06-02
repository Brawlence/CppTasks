#include <iostream>
#include <chrono>

class CPUBenchmark {
private:
	bool _is_started = false;
	uint64_t _cpu_time_start;
	uint64_t _result = 0;

public:
	uint64_t get_current_time_ns() {
		std::chrono::nanoseconds res = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
		return res.count();
	}

	// Начало выполнения запроса
	void begin_measure_time() {

		_is_started = true;

		// Текущее время в наносекундах.
		_cpu_time_start = get_current_time_ns();
	}

	// Окончание выполнения запроса, получение результата
	void finish_measure_time() {

		if (_is_started) {
			_is_started = false;

			// посчитаем время
			_result = get_current_time_ns() - _cpu_time_start;
		}
	}

	uint64_t time_elapsed_ns() {
		return _result;
	}
};

struct ProfileScope {
	CPUBenchmark _benchmark;
	const char *func;
	const char *scope;

	explicit ProfileScope(const char *funcname, const char *scope_=nullptr) :
		func(funcname),
		scope(scope_) {
		_benchmark.begin_measure_time();
	}

	~ProfileScope() {
		_benchmark.finish_measure_time();
		auto dur = _benchmark.time_elapsed_ns() * 1e-6f;

		if (!scope) {
			std::cout << std::endl << "Profile: function " << func << " took " << dur << "ms" << std::endl;
		} else {
			std::cout << std::endl << "Profile: function " << func << " scope " << scope << " took " << dur << "ms" << std::endl;
		}
	}
};


#ifndef CAT_DISABLE_PROFILING
	#define CAT_PROFILE() ProfileScope _prof_util__ {__FUNCTION__}
	#define CAT_PROFILE_SCOPE(x) ProfileScope _prof_util_scope__{__FUNCTION__, x}
#else
	#define CAT_PROFILE() do {} while(0)
	#define CAT_PROFILE_SCOPE(x) do {} while(0)
#endif