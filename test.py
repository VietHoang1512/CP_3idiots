# pip install pytube==10.4.1
# pip install -U get-video-properties
import csv
import pytube
import os
import pandas as pd
import urllib.request
from videoprops import get_video_properties


def downloadYoutube(filename, url):
    youtube = pytube.YouTube(url)
    video = youtube.streams.first()
    out_file = video.download("videos/")
    extension = out_file.split(".")[-1]
    youtube_id_filename = filename+"."+extension
    os.rename(out_file, "videos/"+youtube_id_filename)


def downloadIMDB(filename, url):
    videoplayerlink = url
    html = ""
    with urllib.request.urlopen(videoplayerlink) as response:
        html = response.read()
    html = str(html)
    script = html.split('"video/mp4')
    videoLink = script[1].split('},{')[0].split('"')[4][0:-2]

    urllib.request.urlretrieve(videoLink, "videos/"+filename+".mp4")


if not os.path.exists("videos"):
    os.mkdir("videos")
final_videos = []

csvFile = pd.read_csv(
    'Dataset_ComicMischief_Training_Scene_Multiclass_Annotations.csv')


def compute_frame_rate_from_string_fraction(fraction):
    num, den = fraction.split('/')
    result = float(num)/float(den)
    return result


# Main Script - Downloading Videos from both Youtube and IMDB
totalSuccessfullAttempts = 0
missingVideos = 0
for i, URL in enumerate(csvFile["Video URL"]):
    if(i == 0 or (csvFile["Video URL"][i-1] not in URL)):
        try:
            if "youtube" in URL:
                downloadYoutube(csvFile["Video ID"][i], URL)

            if "imdb" in URL:
                downloadIMDB(csvFile["Video ID"][i], URL)
            props = get_video_properties(
                "videos/"+csvFile["Video ID"][i]+".mp4")
            print("Video ID:" + "\t"+csvFile["Video ID"][i] + "\t URL: \t" + URL+"\t"+"Codec:"+"\t" + props['codec_name']+"\t" + "Resolution:"+"\t" + str(
                props['width']), "x", str(props['height']) + "\t" + "Avg Frame rate:" + "\t" + str(compute_frame_rate_from_string_fraction(props['avg_frame_rate'])))
            totalSuccessfullAttempts += 1
        except:
            print("Video ID: " + "\t"+csvFile["Video ID"][i] +
                  "\t URL: \t" + URL+"\t" + "Unable to download video")
            missingVideos += 1
print("Total Successfull Attempts = ", totalSuccessfullAttempts)
print("Missing Videos = ", missingVideos)
