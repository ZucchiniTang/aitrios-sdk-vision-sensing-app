import json
import subprocess
from pathlib import Path

import cv2
import matplotlib.pyplot as plt
import numpy as np

# You must not change following defines.
# for AI model trained in Console for AITRIOS
INPUT_SIZE = 320
DNN_OUTPUT_DETECTIONS = 2

# Vision and Sensing Application can use this parameter to limit the the number of objects
# detected by AI model in an image. In this case, if AI model detects more than 10 obejects,
# Vision and Sensing Application outputs only 10 objects which has higher precision.
MAX_DETECTIONS = 10

# version number of Vision and Sensing Application for Zone Detection
APP_VERSION_NUMBER = "01.01.00"

# You must not change following defines. You can skip reading them to understand the SDK.

SDK_ENV_ROOT_DIR = "../.."

VNSAPP_CODE_CLONE_DIR = (
    f"{SDK_ENV_ROOT_DIR}"
    "/.devcontainer/dependencies/aitrios-sdk-keypoint-detection-webapp-cs"
)
VNSAPP_CODE_DIR = "sample"
VNSAPP_DIR = "application"


def run_shell_command(command: str):
    """Run shell command with output log and checking return code."""

    with subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        shell=True,
        stderr=subprocess.STDOUT,
        bufsize=1,
        close_fds=True,
    ) as process:
        # for line in iter(process.stdout.readline, b""):
        while True:
            line = process.stdout.readline()
            if line:
                print(line.rstrip().decode("utf-8"))
            if process.poll() is not None:
                break
        process.stdout.close()
        return_code = process.wait()
        if return_code != 0:
            raise subprocess.CalledProcessError(process.returncode, process.args)
        

# You must not change following defines. You can skip reading them to understand the SDK.
IMAGES_TRAINING_DIR = "./dataset/images/training"
IMAGES_VALIDATION_DIR = "./dataset/images/validation"

IMAGE_INPUT = f"{IMAGES_VALIDATION_DIR}/standup_image_for_test.png"
image = cv2.cvtColor(cv2.imread(IMAGE_INPUT), cv2.COLOR_BGR2RGB)
image = cv2.resize(image, dsize=(INPUT_SIZE, INPUT_SIZE))

run_shell_command(
    f"cp {VNSAPP_DIR}/Makefile_VnS \
        {VNSAPP_CODE_CLONE_DIR}/{VNSAPP_CODE_DIR}/sample/vision_app/single_dnn/keypointdetection/"
)

def build_wasm():
    """build Vision and Sensing Application and copy the compiled Wasm file to this notebook's
    directory"""

    run_shell_command(f"{VNSAPP_DIR}/build.sh")
    run_shell_command(
        f"cp -f {VNSAPP_CODE_CLONE_DIR}/{VNSAPP_CODE_DIR}"
        "/sample/vision_app/single_dnn/keypointdetection/build/release/"
        "vision_app_keypointdetection.wasm"
        f" ./{VNSAPP_DIR}/"
    )
    print(f"\nCompiled Wasm file path: ./{VNSAPP_DIR}/vision_app_keypointdetection.wasm")

build_wasm()