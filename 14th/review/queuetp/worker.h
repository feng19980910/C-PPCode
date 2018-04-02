// worker.h -- declear the class worker

#ifndef WORKER_H_
#define WORKER_H_

class worker {
	private:
		char name[20];
		char number[20];
		char vocation[20];
	public:
		worker();
		worker(const char * nm, const char * num, const char * vc);
		worker(const worker & wk);
		worker & operator=(const worker & wk);
		bool set_name(const char * nm);
		bool set_number(const char * num);
		bool set_vocation(const char * vc);
		void show() const;
};	

#endif
