/*
 * Video.hpp
 *
 *  Created on: Aug 31, 2023
 *      Author: Lime
 */

#ifndef VIDEO_HPP_
#define VIDEO_HPP_

#include <iostream>
#include <string>
#include <sstream>

class Video {
public:
	std::string video_ID;
	std::string title;
	int views = 0;

	Video() :
			video_ID(""), title(""), views(0) {
	}

	Video(std::string line) {
		std::string dado;
		std::stringstream ss(line);

		getline(ss, dado, ',');
		video_ID = (dado);

		getline(ss, dado, ',');

		getline(ss, dado, ',');
		title = (dado);

		getline(ss, dado, ',');
		getline(ss, dado, ',');
		getline(ss, dado, ',');
		getline(ss, dado, ',');

		getline(ss, dado, ',');
		views = atoi(dado.c_str());
	}

	std::string toString() {
		std::stringstream ss;
		ss << video_ID << ", " << title << ", " << views;
		return ss.str();
	}

	bool operator>(const Video &outroVideo) {
		return views > outroVideo.views;
	}

	bool operator<(const Video &outroVideo) {
		return views < outroVideo.views;
	}

	bool operator==(const Video &outroVideo) {
		return views == outroVideo.views;
	}
};

#endif /* VIDEO_HPP_ */
