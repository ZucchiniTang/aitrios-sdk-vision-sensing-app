# Vision and Sensing Application SDK for AITRIOS&trade;

## Contents <!-- omit in toc -->
- [Overview](#overview)
  - [What you can do with the Vision and Sensing Application SDK](#what-you-can-do-with-the-vision-and-sensing-application-sdk)
  - [Components](#components)
  - [Restrictions](#restrictions)
- [Installation Guide](#installation-guide)
- [Tutorials](#tutorials)
- [Documentation](#documentation)
  - [SDK Functional Specifications](#sdk-functional-specifications)
- [Get a support](#get-a-support)
- [See also](#see-also)
- [Trademark](#trademark)


## Overview
Vision and Sensing Application SDK for AITRIOS is a toolkit for developing AI models and  post-processing applications that can be installed on Edge AI Devices.
The models and post-processing applications can be deployed to Edge AI Devices through Console for AITRIOS.

![overview](./Images_README/overview.png)

### What you can do with the Vision and Sensing Application SDK
- Use GitHub Codespaces (Dev Container) as development environment.
  - You don't need to install any additional tools in your environment.
<br>

- Develop your AI models in the container.
<br>

- Develop post-processing applications using build environment and sample code included in the container.
<br>

- Import AI models and post-processing applications to Console for AITRIOS and deploy them to Edge AI Devices.

### Components
Vision and Sensing Application SDK is provided as Development Container (Dev Container) that runs on GitHub Codespaces or Docker environment on Local PC.
This container includes tools and jupyter notebooks that can be used for development.


  ```mermaid
  graph TB;
    %% definition
    classDef object fill:#FFE699, stroke:#FFD700
    classDef device fill:#FFFFFF
    classDef sdk fill:#FFFFFF, stroke:#6b8e23, stroke-dasharray: 10 2
    classDef external_service fill:#BFBFBF, stroke:#6b8e23, stroke-dasharray: 10 2
    style legend fill:#FFFFFF, stroke:#000000

    %% impl
    subgraph legend["legend"]
    process(Process)
    object[Data/Artifact]:::object
    sdk[SDK]:::sdk
    extern[External Service]:::external_service
    device[Device]:::device
    end

  ```

#### Workflow for developing AI models
```mermaid
%%{init: {'theme': 'default'}}%%
graph TB;
    style DevContainer fill:#FFFFFF, stroke:#6b8e23, stroke-dasharray: 10 2
    style Console fill:#BFBFBF, stroke:#6b8e23, stroke-dasharray: 10 2
    style your_env fill:#BFBFBF, stroke:#6b8e23, stroke-dasharray: 10 2

    classDef object fill:#FFE699, stroke:#FFD700
    classDef device fill:#FFFFFF

    prepare_sdk(Prepare Dataset)
    train_sdk(Train Model)
    quantize_sdk(Quantize Model)

    train_yours(Train Model)

    prepare_console(Prepare Dataset)
    train_console(Create/Train Model)
    quantize_console(Quantize Model)
    deploy_console(Deploy)
    eval_console(Evaluate)

    img_sdk[Images]:::object
    img_console[Images]:::object
    data_sdk[Dataset]:::object
    data_console[Dataset]:::object
    ai_model[AI-Model]:::object
    custom_model[Your<br>AI-Model]:::object
    quantize_model_sdk[Quantized<br>TFLite-Model]:::object
    quantize_model_console[Quantized<br>TFLite-Model]:::object
    eval_result_sdk[Evaluation<br>Result]:::object
    eval_result_console[Evaluation<br>Result]:::object

    device[Edge AI Device]:::device

    subgraph your_env[Your Training Environment]
        train_yours
    end

    subgraph Console["Console for AITRIOS"]
        img_console --> prepare_console
        prepare_console --> data_console

        data_console --> train_console
        train_console --> ai_model
        ai_model --> quantize_console
        quantize_console --> quantize_model_console
        quantize_model_console --> deploy_console
        eval_console --> eval_result_console
        
    end

    deploy_console --> device
    device --> eval_console

    subgraph DevContainer[Vision and Sensing Application SDK Dev Container]
        prepare_sdk --> img_sdk
        img_sdk --> prepare_sdk
        prepare_sdk --> data_sdk
        data_sdk --> train_sdk
        train_sdk --> custom_model
        custom_model --> quantize_sdk
        %%img_sdk --> quantize_sdk
        quantize_sdk --> quantize_model_sdk
        quantize_sdk --> eval_result_sdk
    end

    data_sdk --> train_yours
    img_sdk --> train_yours
    train_yours --> custom_model
    img_sdk --> img_console
    quantize_model_sdk --> deploy_console


```

#### Workflow for developing post-processing applications
```mermaid
%%{init: {'theme': 'default'}}%%
graph TB;
    style DevContainer fill:#FFFFFF, stroke:#6b8e23, stroke-dasharray: 10 2
    style Console fill:#BFBFBF, stroke:#6b8e23, stroke-dasharray: 10 2

    classDef object fill:#FFE699, stroke:#FFD700
    classDef device fill:#FFFFFF

    ppl_code[Application Code<br>C/C++]:::object
    output_tensor[Output Tensor<br>.jsonc]:::object
    ppl_parameter[PPL Parameter<br>.json]:::object
    wasm[Appliaction<br>.wasm]:::object
    wasm2[Appliaction<br>.wasm]:::object
    aot[Application<br>.aot]:::object
    eval_result[Evaluation<br>Result]:::object

    develop(Develop post-processing Application)
    build_wasm(Build)
    debug_wasm(Run / Debug)
    compile_aot(Compile)
    deploy(Deploy)
    eval(Evaluate)

    device[Edge AI Device]:::device

    subgraph DevContainer[Vision and Sensing Application SDK Dev Container]
        develop --> ppl_code
        ppl_code --> build_wasm
        build_wasm --> wasm
        wasm --> debug_wasm
        output_tensor --> debug_wasm
        ppl_parameter --> debug_wasm
    end

    subgraph Console["Console for AITRIOS"]
        wasm2 --> compile_aot
        compile_aot --> aot
        aot --> deploy
        eval --> eval_result
    end

    wasm --> wasm2
    deploy --> device
    device --> eval

```


- **Console for AITRIOS** <br>
Following functions are available on Console for AITRIOS:
    - manage device
    - upload image from device
    - import image from your local PC or storages
    - import AI model
    - import post-processing application
    - deploy model and post-processing application to device
    - create model
    - annotate image (for AI model created on Console for AITRIOS)
    - train model (for AI model created on Console for AITRIOS)

<br>

- **Dev Container** <br>
Dev Container provides tools and notebooks to support cases where you want to create your own AI model and run it on Edge AI Devices.<br>
Following functions are available on Dev Container.
  - Prepare dataset:
    - Jupyter notebook for downloading images
    - Tools for image annotation
  - Prepare models:
    - Jupyter notebook for training models
    - Jupyter notebook for quantizing models
    - Jupyter notebook for importing models to Console for AITRIOS
    - Jupyter notebook for deploying models to Edge AI Devices
  - Prepare applications:
    - Tools for developing, building and debugging post-processing applications
    - Jupyter notebook for importing applications to Console for AITRIOS
    - Jupyter notebook for deploying applications to Edge AI Devices
  - See [Tutorials](./tutorials/README.md) for details on each notebook and tool.

### Restrictions

#### About Vision and Sensing Application SDK

- AI model training
    - Datasets for Object Detection created on the Dev Container cannot be used for training base AI models (only for training user's custom AI models).
<br>

- AI model quantization on Dev Container
    - Supported AI models are based on [Model Compression Toolkit (MCT)'s features](https://github.com/sony/model_optimization/tree/v1.7.1#supported-features).
<br>

- Jupyter specification
    - Variables in jupyter notebook are cleared when GitHub Codespaces stop.

#### About AITRIOS

- Evaluation of output results
    - Images and inference results output from devices cannot be downloaded from Console for AITRIOS.
    - Inference results displayed on Console for AITRIOS are serialized. 
    - Images and inference results can be downloaded using API, but since the inference results are serialized, the deserializer is required. 
        - See [Cloud SDK Deserialize Sample Tutorial](https://developer.aitrios.sony-semicon.com/development-guides/tutorials/cloud-sdk/) for details.
    
<br>

- Device operation
    - Edge AI Devices can only be operated through Console for AITRIOS.
<br>

#### About GitHub Codespaces

- Codespaces specification
    - It takes about 15 minutes to start a container on Codespaces for the first time. From the second time onwards, it starts up within 1 minute.
    - By default, a container on Codespaces continues running for 30 minutes without any operation. You can change the settings for up to 4 hours.

## Installation Guide

See [Development Environment Setup Guide](https://developer.aitrios.sony-semicon.com/development-guides/get-started/setup-dev/).
<br>

>**NOTE**
>
> - 4-core (8GB) or higher machine types are recommended when using the SDK on Codespaces.
>     - If 2-core is selected, an error may occur during dev container build.
> - To ensure security of connection for CVAT, do NOT make [Codespace's port forwarding sharing option](https://docs.github.com/en/codespaces/developing-in-codespaces/forwarding-ports-in-your-codespace) "Public".

## Tutorials
You can start the development workflow using the tutorial. <br>
See [Vision and Sensing Application SDK tutorials](./tutorials/README.md).


## Documentation
### SDK Functional Specifications
- Prepare dataset
    - [Image Download Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_ImageDownload.pdf)
    - [Image Annotation CVAT Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_ImageAnnotationCvat.pdf)

- Prepare model
    - [Model Training Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_ModelTraining.pdf)
    - [Model Quantization Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_ModelQuantization.pdf)

- Prepare application
    - [Post Vision App Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_PostVisionApp.pdf)

- Setup Console Access Library
    - [Console API Initialize Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_APIInitialize.pdf) 

- Import AI model and application to Console for AITRIOS
    - [AI model and application Import Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_ModelAndPPLImport.pdf)

- Deploy AI model and application to Edge AI Device
    - [AI model and application Deploy Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_ModelAndPPLDeploy.pdf)

- Development container
    - [Development Container Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_DevelopmentContainer.pdf)

- Version control
    - [Version Control Functional Specifications](./docs/development-docs/PDF/VisionandSensingApplicationSDK_FuncSpec_VersionControl.pdf)

## Get support
- [Contact us](https://developer.aitrios.sony-semicon.com/contact-us/)

## See also
- [Console for AITRIOS](https://console.aitrios.sony-semicon.com/)
- [Console Manual](https://developer.aitrios.sony-semicon.com/development-guides/documents/manuals/)
- [Cloud SDK Visualization Tutorial](https://developer.aitrios.sony-semicon.com/development-guides/tutorials/cloud-sdk/)

## Trademark
- [Read This First](https://developer.aitrios.sony-semicon.com/development-guides/documents/manuals/)

